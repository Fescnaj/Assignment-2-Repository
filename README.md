# Assignment-2-Repository
The Repository for assignment two.


I coded a generic dynamic array in c++ with the prompt of the person asking for amount of burgers (number of elements) and then the quantity of patties (value of element). This generic dynamic array has, template based implementation, dynamic resizing, bounds checking, copy and move semantics, iterator support. I achived this by firstly declaring the template, then creating a rezising function to double the capacity and copy the exhisting elements to a new data block when the capacity is full, then the operators, constructor reallocates storage with the updated capacity and the deconstructors get rid of the old data to free memory up. Then the push_back allows for the user to insert a new value to the array hence after resizing. There is also element accessing that has bound checking by checking if the index is valid, if not then it gives an error. Finally, the array has return pointers which allow for range based loops to be used like for loops. 

Video link: 

https://drive.google.com/file/d/1w-kCQ7Ib7T9Hvzz3DTht02p9myFf3b2l/view?usp=sharing
