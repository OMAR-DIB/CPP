#ifndef ITER_HPP
#define ITER_HPP

# include<iostream>

template <typename arr,typename funct>
void iter(arr *array,size_t len,funct function)
{
    for (size_t i = 0; i< len ;i++){
        function(array[i]);
    }
}


#endif