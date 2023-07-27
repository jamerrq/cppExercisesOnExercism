#include "raindrops.h"
#include <string>

namespace raindrops {
    std::string convert(int raindrops){
        std::string result = "";
        int hasFactors = 0;
        if(!(raindrops % 3)){result += "Pling"; hasFactors++;}
        if(!(raindrops % 5)){result += "Plang"; hasFactors++;}
        if(!(raindrops % 7)){result += "Plong"; hasFactors++;}
        if(hasFactors){
            return result;
        }
        return std::to_string(raindrops);
    }
}  // namespace raindrops
