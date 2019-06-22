using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Entidades
{
    public static class GuardaString
    {
        public static bool Guardar(this string texto, string archivo)
        {
            try
            {
                string path = Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory);
                path += "\\" + archivo;
                StreamWriter streamWriter = new StreamWriter(path, true);
                streamWriter.WriteLine(texto);
                streamWriter.Close();
                return true;
                
            } catch(Exception e)
            {
                return false;
            }
        }
    }
}
