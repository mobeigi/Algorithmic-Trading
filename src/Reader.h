//
//  Reader.h
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#ifndef __Algorithmic_Trading_Reader__
#define __Algorithmic_Trading_Reader__

namespace std {
      class Reader;
}

#include <vector>
#include "GlobalIncludes.h"
namespace std {
      class Reader {
      private:
            vector<string> file;
            unsigned at;
      public:
            Reader(string dataFile);
            bool nextTrade();
            vector<string> getTrade();
      };
}
#endif
