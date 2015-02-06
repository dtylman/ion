using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ION
{
    namespace Konzolo
    {
        class ThingVendors : HashSet<String>
        {
            public ThingVendors(string vendor)
            {
                Add(vendor);
                Add("Microsoft");
                Add("Apple");
                Add("Samsung");
                Add("Dell");
            }
        }
    }
}