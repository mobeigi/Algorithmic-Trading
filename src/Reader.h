#ifndef __Algorithmic_Trading_Reader__
#define __Algorithmic_Trading_Reader__

namespace std {
      class Reader {
      private:
            vector<string> file;
            unsigned at;
      public:
            Reader(string dataFile);
            bool nextTrade();
            vector<string> getTrade();
      }
}
