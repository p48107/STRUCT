using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
}using ProyectoCine.Entities;
using System.Threading.Tasks;

namespace ProyectoCine.Mapper
{
    class EmployeeMapper
    {
        private DataAcces.DataAccess _dataAccess;

        private DataAcces.DataAccess DataAccess
        {
            get { return _dataAccess; }
        }

        public EmployeeMapper(DataAcces.DataAccess da)
        {
            _dataAccess = da;
        }

        private int Insert(Employee fund, out string outError)
        {
            string sqlSentence, formatString;

            sqlSentence = "INSERT INTO Fund (ci, nombre, tel, code, username, password, type) VALUES ({0},{1},{2},{3},{4},{5},{6};)";
            sqlSentence = string.Format(sqlSentence, fund.ci, fund.name, fund.tel, fund.code, fund.username, fund.password, fund.type);

            int recordsAffected = 0;
            if (DataAccess.Open())
            {
                recordsAffected = DataAccess.ExecuteCommand(sqlSentence, out outError);
            }
            else
            {
                outError = "Connection could not opened";
            }
            return recordsAffected;
        }

        public DataView GetAllEmployee()
        {
            string sqlSentence;

            sqlSentence = "Select a.* FROM Employee a ORDER BY a.ci";

            DataView dw = null;

            if (DataAccess.Open())
            {
                DataTable dt = DataAccess.GetDataTable(sqlSentence);
                if (dt != null)
                {
                    dw = dt.DefaultView;
                    DataAccess.close();
                }
            }
            return dw;
        }

        public List<Employee> GetAllEmployeesList()
        {
            string sqlSentence;
            List<Employee> list = new List<Employee>();

            sqlSentence = "SELECT a.* FROM Employee a";

            if (DataAccess.Open())
            {
                DataTable dt = DataAccess.GetDataTable(sqlSentence);
                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    DataRow dr = dt.Rows[i];
                    int ci = Convert.ToInt32(dr["ci"]);
                    string name = dr["nombre"].ToString();
                    int tel = Convert.ToInt32(dr["tel"]);
                    string code = dr["code"].ToString();
                    string username = dr["username"].ToString();
                    string password = dr["password"].ToString();
                    string type = dr["type"].ToString();

                    list.Add(new Employee(this, DataAccess, ci, name, tel, code, username, password, type));
                }
                DataAccess.close();
            }
            return list;
        }
    }
}
