using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace WebProgramlama_Proje.Models
{
    public class Library
    {
        public int libraryID { get; set; }//PK
        public int userID { get; set; }
        public int gameID { get; set; }
    }
}
