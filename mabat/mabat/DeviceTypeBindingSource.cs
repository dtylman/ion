using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace mabat
{
    public class DeviceTypeBindingSource : BindingSource
    {
        private List<String> deviceTypes = new List<string>();

        public DeviceTypeBindingSource()
        {
            deviceTypes.Add("Computer");
            deviceTypes.Add("Phone");
            deviceTypes.Add("Tablet");            
            this.DataSource = deviceTypes;
        }
    }
}
