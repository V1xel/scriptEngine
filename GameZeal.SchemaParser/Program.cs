using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;

namespace GameZeal.SchemaParser
{
    class Program
    {
        static List<string> commands = new List<string>();
        static void Main(string[] args)
        {
            Go(@"C:\Users\Vixel\Documents\Visual Studio 2015\Projects\GameZeal.Engine\Schemas\numericExpression.json");
            Go(@"C:\Users\Vixel\Documents\Visual Studio 2015\Projects\GameZeal.Engine\Schemas\literalExpression.json");
            Go(@"C:\Users\Vixel\Documents\Visual Studio 2015\Projects\GameZeal.Engine\Schemas\logicalExpression.json");

            File.WriteAllText("food.json", JsonConvert.SerializeObject(commands));
        }

        static void Go(string filepath)
        {
            var json =
               File.ReadAllText(filepath);
            dynamic MyDynamic = new System.Dynamic.ExpandoObject();
            JsonConvert.PopulateObject(json, MyDynamic);
            IDictionary<string, object> propertyValues = (IDictionary<string, object>)MyDynamic;

            int i = 0;
            foreach (dynamic v in propertyValues)
            {
                dynamic a = v.Value;
                i++;
                if (i == 3)
                {
                    dynamic MyDynamic2 = new System.Dynamic.ExpandoObject();
                    JsonConvert.PopulateObject(a.ToString(), MyDynamic2);
                    IDictionary<string, object> av = (IDictionary<string, object>)MyDynamic2;

                    foreach (var avv in av)
                    {
                        Console.WriteLine(avv.Key + avv.Value);
                        commands.Add(avv.Key);
                    }

                }
            }
        }
    }
}
