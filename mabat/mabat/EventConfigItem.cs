using System;
using System.Collections.Generic;
using System.Linq;
using System.Resources;
using System.Text;
using System.Threading.Tasks;

namespace mabat
{
    public class EventConfigItem
    {
        private string name;
        private string displayName;
        private Boolean mail;
        private bool save;
        private bool syslog;
        
        public EventConfigItem(string name, IonProperties properties)
        {
            this.name = name;
            this.displayName = Strings.ResourceManager.GetString(name);
            this.mail = Boolean.Parse(properties.Get(String.Format("ion.events.{0}.mail", name)));
            this.save = Boolean.Parse(properties.Get(String.Format("ion.events.{0}.save", name)));
            this.syslog = Boolean.Parse(properties.Get(String.Format("ion.events.{0}.syslog", name)));
        }

        public String DisplayName
        {
            get
            {
                return this.displayName;
            }
        }

        public bool Mail { 
            get
            {
                return this.mail;
            }
            set
            {
                this.mail = value;
            }
        }

        public bool Syslog
        {
            get
            {
                return this.syslog;
            }
            set
            {
                this.syslog = value;
            }
        }

        public bool Save
        {
            get
            {
                return this.save;
            }
            set
            {
                this.save = value;
            }
        }
       
    }
}
