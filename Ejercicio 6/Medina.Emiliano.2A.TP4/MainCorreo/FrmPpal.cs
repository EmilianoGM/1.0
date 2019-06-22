using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Entidades;

namespace MainCorreo
{
    public partial class FrmPpal : Form
    {
        private Correo correo;
        public FrmPpal()
        {
            InitializeComponent();
            this.correo = new Correo();
        }

        private void btnAgregar_Click(object sender, EventArgs e)
        {
            string id;
            string direccion;
            if (this.mtxTrackingID.MaskFull)
            {
                id = this.mtxTrackingID.Text;
            }
            else
            {
                MessageBox.Show("El id no se ha completado");
                return;
            }
            direccion = this.txtDireccion.Text;
            if(!String.IsNullOrEmpty(id) && !String.IsNullOrEmpty(direccion))
            {
                Paquete paquete = new Paquete(direccion, id);
                paquete.InformaEstado += new Paquete.DelegadoEstado(this.paq_InformaEstado);
                try
                {
                    correo += paquete;
                } catch (TrackingIdRepetidoException exception)
                {
                    MessageBox.Show(exception.Message);
                }
                this.ActualizarEstados();
            }
            else
            {
                MessageBox.Show("Valores incompletos");
            }
            
        }

        private void btnMostrarTodos_Click(object sender, EventArgs e)
        {
            this.MostrarInformacion(this.correo.MostrarDatos());
        }

        private void paq_InformaEstado(object sender, EventArgs e)
        {
            if (this.InvokeRequired)
            {
                Paquete.DelegadoEstado d = new Paquete.DelegadoEstado(paq_InformaEstado);
                this.Invoke(d, new object[] { sender, e });
            }            else
            {
                this.ActualizarEstados();
            }
        }

        private void FrmPpal_FormClosing(object sender, FormClosingEventArgs e)
        {
            this.correo.FinEntregas();
        }

        private void ActualizarEstados()
        {
            this.lstEstadoIngresado.Items.Clear();
            this.lstEstadoEnViaje.Items.Clear();
            this.lstEstadoEntregado.Items.Clear();
            foreach(Paquete paquete in this.correo.Paquetes)
            {
                switch (paquete.Estado)
                {
                    case Paquete.EEstado.Ingresado:
                        this.lstEstadoIngresado.Items.Add(paquete);
                        break;
                    case Paquete.EEstado.EnViaje:
                        this.lstEstadoEnViaje.Items.Add(paquete);
                        break;
                    case Paquete.EEstado.Entregado:
                        this.lstEstadoEntregado.Items.Add(paquete);
                        break;
                    default:
                        break;
                }
            }
        }

        //BORRAR
        private void MostrarInformacion(string valores)
        {
            if(!Object.Equals(valores, null))
            {
                this.rtbMostrar.Text = valores;
            }
        }

        /*
        private void MostrarInformacion<T>(IMostrar<T> elemento)
        {
            if(!Object.Equals(elemento, null))
            {

            }
        }
        */
    }
}
