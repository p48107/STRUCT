using System;
using System.Collections.Generic;
using ProyectoCine.Mapper;
using ProyectoCine.Entities;
using ProyectoCine.Global;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace ProyectoCine.Controllers
{
    class MainController
    {
        private DataAcces.DataAccess _dataAccess;
        private EmployeeMapper _employeeMapper;
        private List<Employee> _employees;

        private EmployeeMapper Mapper
        {
            get { return _employeeMapper; }
        }

        public MainController()
        {
            string constr = GlobalData.connectionString;

            _dataAccess = new DataAcces.DataAccess(constr);
            _employeeMapper = new EmployeeMapper(_dataAccess);

            GetEmployees();
        }
        public List<Employee> Employees
        {
            get { return _employees; }
        }

        private void GetEmployees()
        {
            _employees = Mapper.GetAllEmployeesList();
        }
    }

}
