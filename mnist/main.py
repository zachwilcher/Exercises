import sys
import numpy as np
import pickle
import gzip


from network import Network



def load_mnist():
    """Returns a tuple of 2 lists of tuples: (label, pixels)"""

    def load_pickle_gzip(filename):
        with gzip.open(filename, 'rb') as f:
            return pickle.load(f)

    training_data, test_data = load_pickle_gzip('./mnist.pickle.gzip')
    return (training_data, test_data)



def preprocess_mnist_data(data):
    def vectorize_label(label):
        v = np.zeros((10, 1))
        v[label] = 1.0
        return v

    return [(np.array(pixels).reshape(784, 1), vectorize_label(label)) for label, pixels in data]





def dump_network(filename, net):
    with open(filename, 'wb') as f:
        pickle.dump(net, f)

def load_network(filename):
    with open(filename, 'rb') as f:
        return pickle.load(f)

def main(argv):

    print('Loading mnist dataset...')
    (training_data, test_data) = load_mnist()
    print(f"Loaded {len(training_data)} training entries and {len(test_data)} test entries")

    print('preprocessing mnist training data...')
    preprocessed_training_data = preprocess_mnist_data(training_data)
    print('preprocessing mnist training data...')
    preprocessed_test_data = preprocess_mnist_data(test_data)

    net = Network([784, 30, 10])

    print('training...')
    net.train(preprocessed_training_data, 30, 10, 3.0, preprocessed_test_data)

    print('saving network...')
    dump_network('network.pickle', net)


if __name__ == "__main__":
    main(sys.argv)