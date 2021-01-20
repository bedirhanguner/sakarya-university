using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace WebProgramlama_Proje.Models
{
    public class ViewModel
    {
        public IEnumerable<Game> Games { get; set; }
        public IEnumerable<Comment> Comments { get; set; }
        public IEnumerable<User> Users { get; set; }
        public IEnumerable<Library> Libraries { get; set; }
    }
}
