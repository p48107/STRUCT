using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.OleDb;
using System.Threading.Tasks;

namespace ProyectoCine.DataAcces
{
    class DataAccess
    {
        private OleDbConnection _connection;
        private string _connectionString;

        public DataAccess(string connectionString)
        {
            _connectionString = connectionString;
        }

        public string ConnectionString
        {
            get { return _connectionString; }
            set { _connectionString = value; }
        }

        public bool Open()
        {
            try
            {
                if (string.IsNullOrEmpty(_connectionString))
                    return false;

                _connection = new OleDbConnection();
                _connection.ConnectionString = _connectionString;

                _connection.Open();
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }
        public bool close()
        {
            try
            {
                if (_connection.State == ConnectionState.Open)
                    _connection.Close();
                return true;
            }
            catch
            {
                return false;
            }
        }

        public DataTable GetDataTable(string p_str_sql)
        {
            string strconn = ConnectionString;

            DataTable dt = new DataTable();
            OleDbDataAdapter sqlDa = new OleDbDataAdapter(p_str_sql, _connection);
            try
            {
                sqlDa.Fill(dt);
                return dt;
            }
            catch (Exception)
            {
                return null;
            }
        }
        public int ExecuteCommand(string str_sql, out string io_error)
        {
            OleDbCommand l_comando;

            try
            {
                l_comando = new OleDbCommand();
                l_comando.CommandText = str_sql;
                l_comando.Connection = _connection;
                io_error = "Success";
                return l_comando.ExecuteNonQuery();
            }
            catch (Exception e)
            {
                io_error = e.Message;
                return 0;
            }
        }
    }
}
