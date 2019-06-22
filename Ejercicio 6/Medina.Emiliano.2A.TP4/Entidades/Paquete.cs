using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Paquete /*: IMostrar<Paquete>*/
    {
        public delegate void DelegadoEstado(object sender, EventArgs args);
        public enum EEstado
        {
            Ingresado,
            EnViaje,
            Entregado
        }

        public event DelegadoEstado InformaEstado;

        private string direccionEntrega;
        private EEstado estado;
        private string trackingID;

        public string DireccionEntrega
        {
            get
            {
                return this.direccionEntrega;
            }
            set
            {
                this.direccionEntrega = value;
            }
        }

        public EEstado Estado
        {
            get
            {
                return this.estado;
            }
            set
            {
                this.estado = value;
            }
        }

        public string TrackingID
        {
            get
            {
                return this.trackingID;
            }
            set
            {
                this.trackingID = value;
            }
        }

        public Paquete(string direccionEntrega, string trackingID)
        {
            this.direccionEntrega = direccionEntrega;
            this.trackingID = trackingID;
        }

        //BORRAR
        public string MostrarDatos() 
        {
            return string.Format("{0} para {1}", this.trackingID, this.direccionEntrega);
        }
        /*
        public string MostrarDatos(IMostrar<Paquete> elemento) //  CAMBIAR
        {
            return string.Format("{0} para {1}", this.trackingID, this.estado);
        }
        */
        public override string ToString()
        {
            return this.MostrarDatos();
        }

        public void MockCicloDeVida()
        {
            while(this.estado != EEstado.Entregado)
            {
                System.Threading.Thread.Sleep(4000);
                int numeroDeEstado = (int)this.estado;
                this.estado = (EEstado)(numeroDeEstado + 1);
                this.InformaEstado(this.estado, new EventArgs());
                //Guardar datos paquete en base de datos
            }
        }

        public static bool operator ==(Paquete p1, Paquete p2)
        {
            if(!Object.Equals(p1, null) && !Object.Equals(p2, null))
            {
                if(p1.trackingID == p2.trackingID)
                {
                    return true;
                }
            }
            return false;
        }

        public static bool operator !=(Paquete p1, Paquete p2)
        {
            return (p1 == p2);
        }
    }
}
