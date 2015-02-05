using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mabat
{
    class ThingDataRow
    {
        public static readonly string Type = "type";
        public static readonly string Vendor = "vendor";
        public static readonly string OS = "os";
        public static readonly string Name = "name";        
        public static readonly string LastSeen = "last_seen";
        public static readonly string MAC = "mac";
        public static readonly string IP = "ip";
        public static readonly string DESC = "desc";
        public static readonly string HWVendor = "hw_vendor";
        public static readonly string Auth = "auth";

        public static String DisplayName(string name)
        {
            return name;
        }
    }
}
