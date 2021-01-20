using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace WebProgramlama_Proje.Models
{
    public class Game
    {
        public int gameID { get; set; }//PK
        public string gameName { get; set; }
        public int gamePrice { get; set; }
        public string gameGenre { get; set; }
        public DateTime gameRD { get; set; }
        public int gameSold { get; set; }
        public string gameDesc { get; set; }
        public string gameURL { get; set; }
        public string gameIMG { get; set; }
    }
}
