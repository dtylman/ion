using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
namespace ION
{
    namespace Konzolo
    {
        public class IonProperties
        {
            private Dictionary<string, string> proeprties = new Dictionary<string, string>();
            private string fileName;

            public IonProperties()
            {
                this.fileName = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "config", "ion.properties");
                Load();
            }

            public void Load()
            {
                foreach (string line in File.ReadAllLines(fileName, Encoding.UTF8))
                {
                    string row = line.Trim();
                    if (row.StartsWith("!") || row.StartsWith("#")) // comment
                    {
                        continue;
                    }
                    int pos = row.IndexOf(':');
                    if (pos < 0)
                    {
                        continue;
                    }
                    string key = row.Substring(0, pos).Trim();
                    string value = row.Substring(pos + 1).Trim();
                    this.proeprties.Add(key, value);
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

            internal void Set(string name, bool value)
            {
                if (value)
                {
                    this.proeprties[name] = "true";
                }
                else
                {
                    this.proeprties[name] = "false";
                }
            }

            [MethodImpl(MethodImplOptions.Synchronized)]
            internal void Save()
            {
                StreamWriter writer = new StreamWriter(this.fileName, false);
                foreach (KeyValuePair<string, string> pair in this.proeprties)
                {
                    writer.WriteLine(pair.Key.Trim() + ": " + pair.Value.Trim());
                }
                writer.Flush();
                writer.Close();
            }

            internal void Set(string key, string value)
            {
                this.proeprties[key] = value;
            }
        }

    }
}