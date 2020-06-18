#include <algorithm>
#include <fstream>
#include <iostream>
#include <list> 
#include "vector"
#include <string.h>

#define BYTE_LENGTH 1024


void printNestedList(std::list<std::list<int> > BYTE_ORDER_MARKS); 

int main(int argn, char** args)
{


    const char *filename = args[1];
    std::ifstream mySource;
    mySource.open(filename, std::ios_base::binary);
    mySource.seekg(0, std::ios_base::end);
    int size = mySource.tellg();
    mySource.close();
    int byte_length = (size>BYTE_LENGTH)?(BYTE_LENGTH):(size);

    std::cout<<"file_size:"<<size<<std::endl;

    //std::cout<<byte_length<<std::endl;
    
    //checking first 1024 bytes
    int buffer[byte_length];
    std::ifstream fstr(filename, std::ios::in | std::ios::binary);

    for (int i = 0; i < byte_length; i++){
        buffer[i] = fstr.get();
        //std::cout<<buffer[i]<<std::endl;
    }


    //fstr.read(buffer, byte_length);

    //auto size = strlen(fstr.str().c_str());

    if(!fstr){
        std::cout<<fstr.gcount()<<std::endl;
        std::cout<<"Couldn't read from the file"<<std::endl;
        exit(1);
    }


    std::cout<<"Checking file: "<<filename<<" of size: "<<size<<std::endl;

    bool ascii = false;
    bool binary = false;

    /* Following algorithm is taken form this link:
     * https://stackoverflow.com/a/277568
    */
    //checking for Ascii
    for (size_t i = 0; i < size; i++)
    {
        if ( ( (buffer[i] >= 9) && (buffer[i] <= 13) ) ||  
            ( (buffer[i] >= 32) && (buffer[i] <= 126) ) )
        {
            ascii = true;
        }
        else
        {
            ascii = false;
            //std::cout<<"Ascii Check Inturrupted!"<<std::endl;
            break;
        }
        
    }

    if(ascii == true)
    {
        std::cout<<filename<<" is pure Ascii"<<std::endl;
        return 0;
    }

    /* text file in an 8-bit
     * or variable-length ASCII-based 
     * encoding such as ISO-8859-1, 
     * UTF-8 or ASCII+Big5
    */
   for (size_t i = 0; i < size; i++)
   {
       if ( (buffer[i] >= 128) && (buffer[i] <= 255) )
       {
           ascii = true;
       }
       else
       {
           ascii = false;
           //std::cout<<"text file check Intrrupted";
           std::cout<<std::endl;
           break;
       }
       
   }

   if (ascii == true)
   {
       std::cout<<filename<<" is a text"<<std::endl;
       return 0;
   }

   //Null check
   for (size_t i = 0; i < BYTE_LENGTH; i++)
   {
       if (buffer[i] == NULL)
       {
           binary = true;
           std::cout<<"Binary File"<<std::endl;
           return 0;
       }
       else
       {
           binary = false;
       }
       
       
   }

   for (size_t i = 0; i < size; i++)
    {
        if ( ( (buffer[i] >= 9) && (buffer[i] <= 13) ) ||  
                ( (buffer[i] >= 32) && (buffer[i] <= 126) )||
                ( (buffer[i] >= 128) ) )
        {
            std::cout<<"text file"<<std::endl;
            return 0;
        }
    }

   //Examining Byte Order Mark (BOM) to inspect encoding
//    if (buffer[0] == 0XFE && buffer[1] == 0XFF){
//        goto UTF16_BE;
//    }
//    else if ((buffer[0] == 0XFF && buffer[1] == 0XFE) &&
//             (buffer[2] != 0X00 && buffer[3] != 0X00) )
//    {
//        goto UTF16_LE;
//    }
//    else if ((buffer[0] == 0X00 && buffer[1] == 0X00) &&
//             (buffer[2] == 0XFE && buffer[3] == 0XFF) )
//    {
//        goto UTF32_BE;
//    }
//    else if ((buffer[0] == 0XFE && buffer[1] == 0XFF) &&
//             (buffer[2] == 0X00 && buffer[3] == 0X00) )
//    {
//        goto UTF32_LE;
//    }
   

//    UTF16_BE:
//    {
//    }

//    UTF16_LE:
//    {
//    }

//    UTF32_BE:
//    {
//    }

//    UTF32_LE:
//    {
//    }
   


    



    // //const char *res = std::find(BEGIN, END, '0');
    // bool detected = (std::find(BEGIN, END, 00) != END);
    // // if detected != END then bool is true and there is null chr

    // // if(index)

    // if(detected){
    //     std::cout<<"Ascii"<<std::endl;
    // }else{
    //     std::cout<<"Binary"<<std::endl;
    // }
    // // if (res == END){
    // //     std::cout<<"Ascii"<<std::endl;
    // // }else{
    // //     std::cout<<"Binary"<<std::endl;
    // // }
    

    return 0;
}