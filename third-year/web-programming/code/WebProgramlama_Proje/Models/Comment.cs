using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace WebProgramlama_Proje.Models
{
    public class Comment
    {
        public int commentID { get; set; }//PK
        public int userID { get; set; }
        public int gameID { get; set; }
        public string commentDesc { get; set; }
        public int commentIsRecommend { get; set; }
    }
}
