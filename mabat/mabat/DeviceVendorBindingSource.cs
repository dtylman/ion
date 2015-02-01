using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace mabat
{
    public class DeviceVendorBindingSource : BindingSource
    {
          private List<String> deviceVendors = new List<string>();

          public DeviceVendorBindingSource()
        {
            deviceVendors.Add("DELL");
            deviceVendors.Add("Samsung");
            deviceVendors.Add("Apple");
            this.DataSource = deviceVendors;
        }
    }
}
