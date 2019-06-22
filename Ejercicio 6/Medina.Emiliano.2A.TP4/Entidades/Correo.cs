using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Entidades
{
    public class Correo : IMostrar<List<Paquete>>
    {
        private List<Thread> mockPaquetes;
        private List<Paquete> paquetes;

        public List<Paquete> Paquetes
        {
            get
            {
                return this.paquetes;
            }
            set
            {
                this.paquetes = value;
            }
        }

        public Correo()
        {
            this.mockPaquetes = new List<Thread>();
            this.paquetes = new List<Paquete>();
        }

        //BORRAR
        /*
        public string MostrarDatos()
        {
            string retorno = "";
            foreach(Paquete paquete in this.paquetes)
            {
                retorno += string.Format("{0} para {1} ({2})\n", paquete.TrackingID, paquete.DireccionEntrega , paquete.Estado);
            }
            return retorno;
        }*/
        
        public string MostrarDatos(IMostrar<List<Paquete>> elemento)
        {
            string retorno = "";
            foreach(Paquete paquete in ((List<Paquete>)elemento))
            {
                retorno += string.Format("{0} para {1} ({2})\n", paquete.TrackingID, paquete.DireccionEntrega , paquete.Estado);
            }
            return retorno;
        }

        public void FinEntregas()
        {
            foreach(Thread thread in this.mockPaquetes)
            {
                thread.Abort();
            }
        }

        public static Correo operator +(Correo c, Paquete p)
        {
            if(!Object.Equals(c, null) && !Object.Equals(p, null))
            {
                if(!Object.Equals(c.paquetes, null) && !Object.Equals(c.mockPaquetes, null))
                {
                    foreach(Paquete paquete in c.paquetes)
                    {
                        if(paquete == p)
                        {
                            throw new TrackingIdRepetidoException("Paquete repetido");
                        }
                    }
                    c.paquetes.Add(p);
                    Thread thread = new Thread(p.MockCicloDeVida);
                    c.mockPaquetes.Add(thread);
                    thread.Start();       
                }
            }
            return c;
        }
    }
}
