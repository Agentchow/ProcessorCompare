    #include<stdio.h>
    #include<stdlib.h> 

    int getSize (char * s) {
    /*  returns size of input string */ 
    /*  This function is already complete; you may use it freely. */
        char * t;
        for (t = s; *t != '\0'; t++);
        return t - s;
    }

    void lab_swap_strings(char* strA, char* strB){
        char swap;
        int i = 0;

        while(strA[i] != '\0' || strB[i] != '\0') {
            swap = strA[i];
            strA[i] = strB[i];
            strB[i] = swap;
            i++;
        }
    }

    int lab_str_match(char* strA, char* strB) {
        int i = 0;
        int j = 0;
        while(strA[i] != '\0' && strB[i] != '\0') {
            if(strA[i] != strB[i]) {
                j = 1;
                break;
            }
            i++;
        }

        if(j == 0 && strA[i] == '\0' && strB[i] == '\0'){return 1;}

        return 0;
    }

    int lab_str_cmp(char* strA, char* strB){
        int i = 0;
        int flag = 0;    
        while (flag == 0){
            if (strA[i] > strB[i]){
                flag = 1;
            }
            else if (strA[i] < strB[i]){
                flag = -1;
            }
            if (strA[i] == '\0'){
                break;
            }
            i++;
        }
        return flag;
    }

    void lab_str_upper(char* str){
        int i;
        for (i = 0; str[i]!='\0'; i++) {
            if(str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] -32;
            }
        }
    }

    void lab_str_lower(char* str){
        int i;
        for (i = 0; str[i]!='\0'; i++) {
            if(str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + 32;
            }
        }

    }

    int main() {
        char processors[10][100];
        float costs[10];
        float clockrates[10];
        float cpis[10];
        float executiontimes[10];
        int number_of_processors = 0;

        // Enter in all of the different processors, costs, clock rate and CPI

        printf("Please enter the number of processors [1 to 10]:\n");
        scanf("%d", &number_of_processors );

        for (int i=0; i<number_of_processors; i++ ) {
            printf("Processor Name (no spaces):\n" );
            scanf("%s", processors[i] );
            printf("Processor cost (US dollars):\n" );
            scanf("%f", &costs[i] );
            printf("Processor clock rate (in GHz):\n" );
            scanf("%f", &clockrates[i] );
            printf("Processor average CPI:\n" );
            scanf("%f", &cpis[i] );
        }
        //Execution Time Calc and store in Array
        int c;
        for(c = 0; c < number_of_processors; c ++) {
            executiontimes[c] = (cpis[c] / (100 * clockrates[c]));   
        }

        char type[100];
        int compare;
        char name[] = "name";
        char price[] = "price";
        char rate[] = "rate";
        char time[] = "time";

        printf("Which value would you like to sort on (from lowest to highest)?\n");
        scanf("%s", type);

        int z,i,j; 
        double temp1;
        double tCosts;
        char strTemp[100];

        //Sort by name/strings
        if (lab_str_cmp(name, type) == 0){     
            for(z = 0; z < number_of_processors-1; z++) {
                for (j = 0; j < number_of_processors-1-z; j++){
                    if(lab_str_cmp(processors[j], processors[j+1]) == 1) {
                        //Swap Names
                        lab_swap_strings(processors[j],processors[j+1]);
                        //Swap times
                        temp1 = executiontimes[j];
                        executiontimes[j] = executiontimes[j+1];
                        executiontimes[j+1] = temp1;
                    }
                }
            }
        }
        
        //Sort by price
        if (lab_str_match(price, type) == 1){
            for (z = 0; z < number_of_processors-1; z++){
                for (j = 0; j < number_of_processors-1-z; j++){
                    if (costs[j] > costs[j+1]){
                            //Swap Price 
                            temp1 = costs[j];
                            costs[j] = costs[j+1];
                            costs[j+1] = temp1;
                            //Swap Names
                            lab_swap_strings(processors[j],processors[j+1]);
                    }  
                }
            }        
        }
        //Sort by rate
        if (lab_str_match(rate, type) == 1){
            for (z = 0; z < number_of_processors-1; z++){
                for (j = 0; j < number_of_processors-1-z; j++){
                    if (clockrates[j] > clockrates[j+1]){
                            //Swap Rate 
                            temp1 = clockrates[j];
                            clockrates[j] = clockrates[j+1];
                            clockrates[j+1] = temp1;
                            //Swap Names
                            lab_swap_strings(processors[j],processors[j+1]);
                    }  
                }
            } 
        }

        //Sort by time
        if (lab_str_match(time, type) == 1){
            for (z = 0; z < number_of_processors-1; z++){
                for (j = 0; j < number_of_processors-1-z; j++){
                    if (executiontimes[j] > executiontimes[j+1]){
                            //Swap Execution times
                            temp1 = executiontimes[j];
                            executiontimes[j] = executiontimes[j+1];
                            executiontimes[j+1] = temp1;
                            //Swap Names
                            lab_swap_strings(processors[j],processors[j+1]);

                    }  
                }
            }
        }

        char threshold[100];
        printf("Would you rather place emphasis on values above or below a certain threshold?\n");
        scanf("%s", threshold);

        char above[] = "above";
        char below[] = "below";
            
        int point; 

        //Name Emphasis - Find first instance of name and store
        if(lab_str_match(type, name) == 1) {
            char comparison[100];
            printf("What is the threshold value for your comparison?\n");
            scanf("%s", comparison);
            for(int i = 0; i < number_of_processors; i++) {
                if(lab_str_cmp(comparison, processors[i]) == -1) {
                    point = i;
                    break;
                }
            }
        }
        //For Costs emphasis
        if(lab_str_match(type, price) == 1) {
            float comparison;
            printf("What is the threshold value for your comparison?\n");
            scanf("%f", &comparison);
            for(int i = 0; i < number_of_processors; i++) {
                if(comparison < costs[i]) {
                    point = i;
                    break;
                }
            }
        }
        //Rate Emphasis
        if(lab_str_match(type, rate) == 1) {
            float comparison;
            printf("What is the threshold value for your comparison?\n");
            scanf("%f", &comparison);
            for(int i = 0; i < number_of_processors; i++) {
                if(comparison > clockrates[i+1]) {
                    point = i;
                    break;
                }
            }       
        }
        //Time emphasis
        if(lab_str_match(type, time) == 1) {

            float comparison;
            printf("What is the threshold value for your comparison?\n");
            scanf("%f", &comparison);
            for(int i = 0; i < number_of_processors; i++) {
                if(comparison < executiontimes[i]) {
                    point = i;
                    break;
                }
            }   
        }

        printf("Your emphasized list of processors is...\n");
        //if Above
        i = 0;
        if (lab_str_match(threshold, above) == 1) {
            while(i < point) {
                lab_str_lower(processors[i]);
                i++;
            }
            while(i < number_of_processors) {
                lab_str_upper(processors[i]);
                i++;
            }
        }
        //if Below
        i = 0;
        if (lab_str_match(threshold, below) == 1) {
            while(i < point) {
                lab_str_upper(processors[i]);
                i++;
            }
            while(i < number_of_processors) {
                lab_str_lower(processors[i]);
                i++;
            }        
        }
        for(int o = 0; o < number_of_processors; o++) {
            printf("%s\n", processors[o]);
        }




        return 0;

    }


