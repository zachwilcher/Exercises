
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char** argv) {
    
    srand(time(NULL));
    
    if(argc < 2) {
        printf("usage: %s <simulations>\n", argv[0]);
        exit(1);
    }
    
    int simulations = atoi(argv[1]);
    
    int results[] = {0, 0, 0};

    for(int i = 0; i < simulations; i++) {
        
        //choose the door with the car   
        int car = rand() % 3;

        //choose the door
        int choice = rand() % 3;
        
        //determine if random player switches       
        int change = rand() % 2;

        //add a win for a player who always switches
        if(choice != car) {
            results[0] += 1;
        }
        //add a win for a player who always stays
        else {
            results[1] += 1;
        }
        
        //add win for random player if switch
        if(change == 0) {
            if(choice != car){
                results[2] += 1;
            }
        }
        //add win for random player if stay
        else {
            if(choice == car) {
                results[2] += 1;
            }
        }
        

    }

    printf("wins if only changing: %d\n\
            wins if only staying: %d\n\
            wins if random: %d\n\
            simulations ran: %d\n", results[0], results[1], results[2], simulations);

    return 0;
}


