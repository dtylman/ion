﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace mabat
{
    class ThingOS : HashSet<String>
    {

        public ThingOS(string os)
        {
            Add(os);
            Add("microsoft windows");
            Add("linux");
            Add("google android");
            Add("ios");            
        }
    }
}
