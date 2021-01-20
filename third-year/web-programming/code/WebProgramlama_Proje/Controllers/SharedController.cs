using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using WebProgramlama_Proje.Data;
using WebProgramlama_Proje.Models;

namespace WebProgramlama_Proje.Controllers
{
    public class SharedController : Controller
    {

        private readonly MuslukDbContext _context;

        public SharedController(MuslukDbContext context)
        {
            _context = context;
        }

        public async Task<IActionResult> _Layout()
        {

            ViewModel viewModel = new ViewModel();

            viewModel.Users = _context.User.ToList();
            viewModel.Comments = _context.Comment.ToList();
            viewModel.Games = _context.Game.ToList();
            viewModel.Libraries = _context.Library.ToList();

            return View(viewModel);
        }

        public async Task<IActionResult> _LoginPartial()
        {

            ViewModel viewModel = new ViewModel();

            viewModel.Users = _context.User.ToList();
            viewModel.Comments = _context.Comment.ToList();
            viewModel.Games = _context.Game.ToList();
            viewModel.Libraries = _context.Library.ToList();

            return View(viewModel);
        }
    }
}
