using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace WebProgramlama_Proje.Models
{
    public class User
    {
        public int userID { get; set; }//PK
        public string userName { get; set; }
        public string userPass { get; set; }
        public string userMail { get; set; }
        public int userWallet { get; set; }
        public bool userIsAdmin { get; set; }
        public string userIMG { get; set; }

    }

}

