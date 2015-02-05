using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mabat
{
    public class IonProperties
    {
        private Dictionary<string, string> proeprties = new Dictionary<string, string>();

        public IonProperties()
        {
            Load();
        }
        
        public void Load()
        {
            string fileName = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "config", "ion.properties");
            foreach (string line in File.ReadAllLines(fileName, Encoding.UTF8))
            {
                string row = line.Trim();                                
                if (row.StartsWith("!") || row.StartsWith("#")) // comment
                {
                    continue;
                }
                string[] items = row.Split(':');
                if (items.Length==2)
                {
                    this.proeprties.Add(items[0], items[1]);
                }
            }            
        }

        public string Get(String name)
        {
            if (this.proeprties.ContainsKey(name))
            {
                return this.proeprties[name];
            }
            return "";
        }
    }

}
