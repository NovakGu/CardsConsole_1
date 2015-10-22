
   /*                                                 
					        *************************                            
                   *********                         *********                   
             *******                                         *******             
         ******                                                   ******         
      *****                                                           *****      
    ****                                                                 ****    
  ****                                                                     ****  
****                                                                         ****
***                                                                           ***
***                                                                           ***
***                                                                           ***
***                                                                           ***
***                                                                           ***
****                                                                         ****
  ****                                                                     ****  
    ****                                                                 ****    
      *****                                                           *****      
         ******                                                   ******         
             *******                                         *******             
                   *********                         *********                   
                            *************************                           
							                      
							*/
#include <iostream>


int main()
{
   int circle_radius = 10; // or whatever you want
    float console_ratio = 4.0/1.0;
    float a = console_ratio*circle_radius;
    float b = circle_radius;

    for (int y = -circle_radius; y <= circle_radius; y++)
    {
        for (int x = -console_ratio*circle_radius; x <= console_ratio*circle_radius; x++)
        {
            float d = (x/a)*(x/a) + (y/b)*(y/b);
            if (d > 0.90 && d < 1.1)
            {
                std::cout << "*";
            }
			else if (d>1.1){
				std::cout<<"1";
			}
			else if(d<0.3){
				std::cout<<"2";
			}
            else
            {
                 std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
   return 0;
}


