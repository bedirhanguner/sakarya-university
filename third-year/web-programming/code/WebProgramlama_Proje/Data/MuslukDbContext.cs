using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using WebProgramlama_Proje.Models;

namespace WebProgramlama_Proje.Data
{
    public class MuslukDbContext : DbContext
    {
        public MuslukDbContext(DbContextOptions<MuslukDbContext> options)
            : base(options)
        {
        }


        public DbSet<WebProgramlama_Proje.Models.Game> Game { get; set; }
        public DbSet<WebProgramlama_Proje.Models.User> User { get; set; }
        public DbSet<WebProgramlama_Proje.Models.Comment> Comment { get; set; }
        public DbSet<WebProgramlama_Proje.Models.Library> Library { get; set; }

    }
}
