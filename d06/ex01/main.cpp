/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:49:10 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/08 13:50:06 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>

struct Data {
    std::string s1;
    int n;
    std::string s2;
};

char genRandomAlphaNum()
{
    static const char alphaNum[] = "0123456789"
                                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                    "abcdefghijklmnopqrstuvwxyz";
    return (alphaNum[rand() % sizeof(alphaNum) - 1]);
}

void * serialize(void)
{
    int randInt = rand() % 100;
    char *serializedData = new char[8 + sizeof(int) + 8];
    char *sPtr = serializedData;
    
    for (int i = 0; i < 8; i++)
    {
        *sPtr = genRandomAlphaNum();
        sPtr++;
    }
    
    int *iPtr = reinterpret_cast<int *>(sPtr);
    
    *iPtr = randInt;
    
    for (unsigned long i = 0; i < sizeof(int); i++)
        sPtr++;
    
    for (int i = 0; i < 8; i++)
    {
        *sPtr = genRandomAlphaNum();
        sPtr++;
    }
    
    return (reinterpret_cast<void *>(serializedData));
}

Data * deserialize(void *raw)
{
    Data *data = new Data;
    
    char *sPtr = reinterpret_cast<char *>(raw);
    for (int i = 0; i < 8; i++)
    {
        data->s1.push_back(*sPtr);
        sPtr++;
    }
    
    int *iPtr = reinterpret_cast<int *>(sPtr);
    
    data->n = *iPtr;
    
    for (unsigned long i = 0; i < sizeof(int); i++)
        sPtr++;
    
    for (int i = 0; i < 8; i++)
    {
        data->s2.push_back(*sPtr);
        sPtr++;
    }
    
    return (data);
}

int main() 
{
    srand(time(0));
    void *serializedData = serialize();
    Data *data = deserialize(serializedData);
    
    std::cout << data->s1 << " " << data->n << " " << data->s2 << std::endl;
    return 0;
}
