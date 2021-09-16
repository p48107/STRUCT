using System;
using System.Collections.Generic;
using ProyectoCine.Mapper;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProyectoCine.Entities
{
    class Employee
    {
        private EmployeeMapper _mapper;
        private DataAcces.DataAccess _dataAccess;

        public string name { get; set; }
        public int ci { get; set; }
        public int tel { get; set; }
        public string code { get; set; }
        public string username { get; set; }
        public string password { get; set; }
        public string type { get; set; }

        public Employee(EmployeeMapper mapper, DataAcces.DataAccess dac)
        {
            _mapper = mapper;
            _dataAccess = dac;
        }
        public Employee(EmployeeMapper mapper, DataAcces.DataAccess dac, int ci, string nom, int telf, string code, string username, string password, string type) : this(mapper, dac)
        {
            this.ci = ci;
            this.name = nom;
            this.tel = tel;
            this.code = code;
            this.username = username;
            this.password = password;
            this.type = type;
        }
    }
}
