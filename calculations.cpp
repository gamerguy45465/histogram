#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <cfloat>

extern "C" {


    std::vector<std::string> getData(std::ifstream& File)
    {
        std::vector<std::string> container;

        std::string line;

        while(getline (File, line))
        {
            container.push_back(line);
        }


        return container;

    }


    float nBins(std::vector<std::string>& container)
    {
        return floor(1.87 * pow(((container.size() - 1) - 1), 0.40) + 1);
    }

    float getLow(std::vector<std::string>& container)
    {
        float low = FLT_MAX;

        for(std::string e : container)
        {
            if(stoi(e) < low)
                low = std::stof(e);
        }


        return low;
    }

    float getHigh(std::vector<std::string>& container)
    {
        std::cout << "Entered high" << std::endl;
        float high = FLT_MIN;
        std::cout << "FLT_MIN" << std::endl;

        for(std::string e : container)
        {
            std::cout << "Here" << std::endl;
            if(stoi(e) > high)
                high = std::stof(e);
        }


        return high;

    }

    float delta_x(std::vector<std::string>& container, float bins)
    {
        float low = getLow(container);
        float high = getHigh(container);

        std::cout << low << std::endl;
        std::cout << high << std::endl;

        float diff = high - low;

        std::cout << diff << std::endl;

        return 2 * diff/(bins);


    }

    int main() // This was used for testing purposes only, and does not play a major role in main.py
    {
        std::ifstream File("HW_Ch4_Hist_Data.txt");

        std::vector<std::string> data = getData(File);


        float bins = nBins(data);

        std::cout << delta_x(data, bins) << std::endl;


        return 0;


    }



/*******************VECTOR FUNCTIONS**************************/

    vector<std::string>* new_vector()
    {
        return new vector<std::string>;
    }
    
    void delete_vector(vector<std::string>* v)
    {
        delete v;

    }

    int vector_size(vector<std::string>* v)
    {
        return v->size();

    }

    std::string vector_get(vector<std::string>* v, int i)
    {
        return v->at(i);

    }

    void vector_push_back(vector<std::string>* v, int i)
    {
        return v->push_back(i);

    }



}