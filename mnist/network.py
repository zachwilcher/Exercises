
import numpy as np
import random

def to_label(out):
    """Output of net to int"""

    largest_index = 0
    largest_value = out[largest_index]
    for i in len(out):
        if out[i] > largest_value:
            largest_value = out[i]
            largest_index = i
    return largest_index

def sigmoid(x):
    return 1.0 / (1.0 + np.exp(-x))

def sigmoid_derivative(x):
    y = sigmoid(x)
    return y * (1 - y)

def cost_derivative(activation, output):
    return activation - output


class Layer:

    def __init__(self, size, activation=sigmoid, activation_derivative=sigmoid_derivative):
        """size is a tuple with size[0] = num of outputs, and size[1] = num of inputs"""
        self.size = size

        self.weights = np.random.randn(self.size)

        self.biases = np.random.randn(self.outputs, 1)

        self.activation = activation
        self.activation_derivative = activation_derivative


    def inputs(self):
        """Return the number of inputs of this layer"""
        return self.size[0]

    def outputs(self):
        """Return the number of outputs of this layer"""
        return self.size[1]
    
    def weighted_input(self, input):
        """Calculate the weighted input (z vector) of an input"""
        return np.matmul(self.weights, input) + self.biases

    def feedforward(self, input):
        z = self.weighted_input(input)
        return self.activation(z)




class Network:
    """Simple neural network class."""


    def __init__(self, sizes=[]):
        self.layers = [Layer((outputs, inputs)) for outputs, inputs in zip(sizes[1:], sizes[:-1])]

    def input_layer(self):
        return self.layers[0]

    def output_layer(self):
        return self.layers[-1]

    def feedforward(self, input):
        for layer in self.layers:
            input = layer.feedforward(input)
        return input


    def train(self, data, epochs, batch_size, learning_rate, test_data=None):
        """data is array of tuples (x, y) containing inputs and outputs of training data."""

        # number of data points
        data_count = len(data)

        for epoch in range(epochs):
            
            random.shuffle(data)

            for k in range(0, data_count, batch_size):
                batch_data = data[k:k+batch_size]

                net_weight_changes = [np.zeros(W.shape) for W in self.weights]
                net_bias_changes = [np.zeros(b.shape) for b in self.biases]

                for x, y in batch_data:
                    weight_changes, bias_changes = self.backprop(x, y)
                    net_weight_changes = [W + dW for W, dW in zip(net_weight_changes, weight_changes)]
                    net_bias_changes = [b + db for b, db in zip(net_bias_changes, bias_changes)]

                for layer, weight_changes, bias_changes in zip(self.layers, net_weight_changes, net_bias_changes):
                    layer.weights = learning_rate / batch_size * weight_changes
                    layer.biases = learning_rate / batch_size * bias_changes

            print(f"epoch: {epoch + 1} out of {epochs} complete")

            if test_data is None:
                continue

            correct = 0
            for x, y in test_data:

                label = to_label(y)
                out = self.feedforward(x)
                predicted_label = to_label(out)

                if label == predicted_label:
                    correct += 1

            print(f"{correct} / {len(test_data)} correct")


    def backprop(self, x, y):
        """Calculate gradient of quadratic cost function using backpropagation algorithm.
        'x' and 'y' are inputs and outputs of a batch."""

        # weighted inputs of each layer
        inputs = []
        # activations of each layer (activation of input layer is initial input)
        activations = [x]
        
        # feed forward while saving weighted inputs and activations
        for layer in self.layers:
            inputs.append(layer.weighted_input(activations[-1]))
            activations.append(layer.activation(inputs[-1]))

        # calculate error of last layer
        cd = cost_derivative(activations[-1], y)
        sd = self.output_layer().activation_derivative(inputs[-1])
        errors = [np.multiply(cd, sd)]

        # calculate errors of previous layers 
        for W, input in zip(reversed(self.weights[1:]), reversed(inputs[:-1])):
            sd = sigmoid_derivative(input)
            errors.append(np.multiply(np.matmul(np.transpose(W), errors[-1]), sd))

        # use errors to calculate gradient of cost function with respect to weights and biases
        bias_changes = []
        weight_changes = []
        for error, activation in zip(reversed(errors), activations[:-1]):
            bias_changes.append(error)
            weight_changes.append(np.matmul(error, np.transpose(activation)))

        return (weight_changes, bias_changes)
