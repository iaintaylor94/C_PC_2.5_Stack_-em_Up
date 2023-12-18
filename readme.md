# Programming Challenges
## Problem 2.5: Stack 'em Up[^1]
### Problem description
This program determines the order of a deck of cards after several "shuffles". Each shuffle rearanges the deck of cards into a predetermined order. Initially the deck of cards is arranged alphabetically by suit then by value. The suits are as follows: 

1. Two
2. Three
3. Four
4. five
5. Six
6. Seven
7. Eight
8. Nine
9. Ten
10. Jack
11. Queen
12. King
13. Ace

The input consists of a line denoting the number of test cases to run, followed by a blank line. Then repeats: 
A line containing the number of shuffles (n <= 100);
'n' lines denoting the arrangements of cards after the shuffle;
several lines indicating the shuffle to perform on the deck of cards.
A blank line if computing the next test case, or EOF if at the end of the final test case



### Example 
>**Input**               
>1               
>             
>2                  
>2 1 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 52 51 52               
>2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 1              
>1                
>2                                        

>**Output**                                        
>King of Spades                   
>2 of Clubs                     
>4 of Clubs                          
>5 of Clubs                          
>6 of Clubs                           
>7 of Clubs                                
>8 of Clubs                           
>9 of Clubs                             
>10 of Clubs                                 
>Jack of Clubs                                 
>Queen of Clubs                                      
>King of Clubs                                  
>Ace of Clubs                              
>2 of Diamonds                                        
>3 of Diamonds                               
>4 of Diamonds                              
>5 of Diamonds                                
>6 of Diamonds                              
>7 of Diamonds                                
>8 of Diamonds                                 
>9 of Diamonds                                    
>10 of Diamonds                                      
>Jack of Diamonds                                   
>Queen of Diamonds                                     
>King of Diamonds                                      
>Ace of Diamonds                                  
>2 of Hearts                                 
>3 of Hearts                                        
>4 of Hearts                                        
>5 of Hearts                                     
>6 of Hearts                                 
>7 of Hearts                                 
>8 of Hearts                                   
>9 of Hearts                                        
>10 of Hearts                                         
>Jack of Hearts                                        
>Queen of Hearts                                      
>King of Hearts                                         
>Ace of Hearts                                        
>2 of Spades                                    
>3 of Spades                                           
>4 of Spades                                       
>5 of Spades                                     
>6 of Spades                                               
>7 of Spades                                             
>8 of Spades                              
>9 of Spades                                 
>10 of Spades                                    
>Jack of Spades                                   
>Queen of Spades                                                                    
>Ace of Spades                                          
>3 of Clubs                                            


[^1]: Programming Challenges By S.Skienna and M.Revilla, page 48