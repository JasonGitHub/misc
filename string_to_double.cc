double string_to_double(const string &s){
   istringstream i(s);
   double x;
   if (!(i >> x))
     return 0;
   return x;
 } 
