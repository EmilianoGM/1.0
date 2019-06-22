using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Data;

namespace Entidades
{
  public static class PaqueteDao
  {
    private static SqlCommand comando;
    private static SqlConnection conexion;

    static PaqueteDao()
    {
      conexion = new SqlConnection(Properties.Settings.Default.conexion_db);
    }

    public static bool Insertar(Paquete p)
    {
      comando = new SqlCommand();
      comando.Connection = conexion;
      comando.CommandType = CommandType.Text;
      try
      {
        comando.CommandText = "INSERT INTO[correo-sp-2017].[dbo].[Paquetes](direccionEntrega, trackingID, alumno) values('" +
       p.DireccionEntrega + "','" + p.TrackingID + "','Emiliano Medina')";
        conexion.Open();
        if(comando.ExecuteNonQuery() > 0)
        {
          return true;
        }
      } catch(Exception e)
      {
        throw e;
      }
      finally
      {
        if (conexion.State.Equals(ConnectionState.Open))
        {
          conexion.Close();
        }
      }
      return false;
    } 
  }
}
