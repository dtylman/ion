using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mabat
{
    class ThingTypes : HashSet<String>
    {
        public ThingTypes(string type)
        {
            Add(type);
            Add("Computer");
            Add("Tablet");
            Add("Phone");
            Add("Router");
            Add("TV");            
        }
    }
}
