using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;
using WebProgramlama_Proje.Data;
using WebProgramlama_Proje.Models;

namespace WebProgramlama_Proje.Controllers
{
    public class HomeController : Controller
    {

        MuslukDbContext mdb;

        public HomeController(MuslukDbContext context)
        {
            mdb = context;
        }

        public async Task<IActionResult> Index()
        {

            ViewModel viewModel = new ViewModel();

            viewModel.Users = mdb.User.ToList();
            viewModel.Comments = mdb.Comment.ToList();
            viewModel.Games = mdb.Game.ToList();
            viewModel.Libraries = mdb.Library.ToList();

            return View(viewModel);
        }

        public IActionResult Privacy()
        {
            ViewModel viewModel = new ViewModel();

            viewModel.Users = mdb.User.ToList();
            viewModel.Comments = mdb.Comment.ToList();
            viewModel.Games = mdb.Game.ToList();
            viewModel.Libraries = mdb.Library.ToList();

            return View(viewModel);
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}
