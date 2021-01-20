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
    public class GameController : Controller
    {
        private readonly MuslukDbContext _context;

        public GameController(MuslukDbContext context)
        {
            _context = context;
        }

        // GET: Game
        public async Task<IActionResult> Index()
        {
            return View(await _context.Game.ToListAsync());
        }


        public async Task<IActionResult> tam_hayat()
        {

            ViewModel viewModel = new ViewModel();

            viewModel.Users = _context.User.ToList();
            viewModel.Libraries = _context.Library.ToList();

            var Oyun = from a in _context.Game
                       where a.gameID == 2
                       select a;
            
            var yorum = from a in _context.Comment
                       where a.gameID == 2
                       select a;
            
            viewModel.Comments = yorum;
            viewModel.Games = Oyun;
            
            return View(viewModel);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> tam_hayat(Comment comment)
        {
            User kullanici = new User();
            if (User.Identity.IsAuthenticated)
            {
                foreach(var kul in _context.User)
        {
                    if (kul.userMail == User.Identity.Name )
                    {
                        kullanici = kul;
                        break;
                    }
                }
            }
            comment.userID = kullanici.userID;
            comment.gameID = 2;
            if(comment != null)
            {
                _context.Add(comment);
                _context.SaveChanges();
            }

            return RedirectToAction("tam_hayat", "Game");
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> tam_hayat_al(Library library)
        {
            User kullanici = new User();
            if (User.Identity.IsAuthenticated)
            {
                foreach (var kul in _context.User)
                {
                    if (kul.userMail == User.Identity.Name)
                    {
                        kullanici = kul;
                        break;
                    }
                }
            }
            if (30 <= kullanici.userWallet)
            {
                kullanici.userWallet -= 30;
                library.userID = kullanici.userID;
                library.gameID = 2;
                if (library != null)
                {
                    _context.Add(library);
                    _context.Update(kullanici);
                    _context.SaveChanges();
                }
            }
            return RedirectToAction("tam_hayat", "Game");
        }

        /// <summary>
        /// </summary>
        /// <returns></returns>
        public async Task<IActionResult> sinir_cizgileri()
        {

            ViewModel viewModel = new ViewModel();

            viewModel.Users = _context.User.ToList();
            viewModel.Libraries = _context.Library.ToList();

            var Oyun = from a in _context.Game
                       where a.gameID == 10
                       select a;

            var yorum = from a in _context.Comment
                        where a.gameID == 10
                        select a;

            viewModel.Comments = yorum;
            viewModel.Games = Oyun;

            return View(viewModel);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> sinir_cizgileri(Comment comment)
        {
            User kullanici = new User();
            if (User.Identity.IsAuthenticated)
            {
                foreach (var kul in _context.User)
                {
                    if (kul.userMail == User.Identity.Name)
                    {
                        kullanici = kul;
                        break;
                    }
                }
            }
            comment.userID = kullanici.userID;
            comment.gameID = 10;
            if (comment != null)
            {
                _context.Add(comment);
                _context.SaveChanges();
            }

            return RedirectToAction("sinir_cizgileri", "Game");
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> sinir_cizgileri_al(Library library)
        {
            User kullanici = new User();
            if (User.Identity.IsAuthenticated)
            {
                foreach (var kul in _context.User)
                {
                    if (kul.userMail == User.Identity.Name)
                    {
                        kullanici = kul;
                        break;
                    }
                }
            }
            if (60 <= kullanici.userWallet)
            {
                kullanici.userWallet -= 60;
                library.userID = kullanici.userID;
                library.gameID = 10;
                if (library != null)
                {
                    _context.Add(library);
                    _context.Update(kullanici);
                    _context.SaveChanges();
                }
            }
            return RedirectToAction("sinir_cizgileri", "Game");
        }

        /// <summary>
        /// </summary>
        /// <returns></returns>
        public async Task<IActionResult> parlak_ruhlar()
        {

            ViewModel viewModel = new ViewModel();

            viewModel.Users = _context.User.ToList();
            viewModel.Libraries = _context.Library.ToList();

            var Oyun = from a in _context.Game
                       where a.gameID == 8
                       select a;

            var yorum = from a in _context.Comment
                        where a.gameID == 8
                        select a;

            viewModel.Comments = yorum;
            viewModel.Games = Oyun;

            return View(viewModel);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> parlak_ruhlar(Comment comment)
        {
            User kullanici = new User();
            if (User.Identity.IsAuthenticated)
            {
                foreach (var kul in _context.User)
                {
                    if (kul.userMail == User.Identity.Name)
                    {
                        kullanici = kul;
                        break;
                    }
                }
            }
            comment.userID = kullanici.userID;
            comment.gameID = 8;
            if (comment != null)
            {
                _context.Add(comment);
                _context.SaveChanges();
            }

            return RedirectToAction("parlak_ruhlar", "Game");
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> parlak_ruhlar_al(Library library)
        {
            User kullanici = new User();
            if (User.Identity.IsAuthenticated)
            {
                foreach (var kul in _context.User)
                {
                    if (kul.userMail == User.Identity.Name)
                    {
                        kullanici = kul;
                        break;
                    }
                }
            }
            if (200 <= kullanici.userWallet)
            {
                kullanici.userWallet -= 200;
                library.userID = kullanici.userID;
                library.gameID = 8;
                if (library != null)
                {
                    _context.Add(library);
                    _context.Update(kullanici);
                    _context.SaveChanges();
                }
            }
            return RedirectToAction("parlak_ruhlar", "Game");
        }

        /// <summary>
        /// </summary>
        /// <returns></returns>
        public async Task<IActionResult> kader_karanligin_yukselisi()
        {

            ViewModel viewModel = new ViewModel();

            viewModel.Users = _context.User.ToList();
            viewModel.Libraries = _context.Library.ToList();

            var Oyun = from a in _context.Game
                       where a.gameID == 9
                       select a;

            var yorum = from a in _context.Comment
                        where a.gameID == 9
                        select a;

            viewModel.Comments = yorum;
            viewModel.Games = Oyun;

            return View(viewModel);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> kader_karanligin_yukselisi(Comment comment)
        {
            User kullanici = new User();
            if (User.Identity.IsAuthenticated)
            {
                foreach (var kul in _context.User)
                {
                    if (kul.userMail == User.Identity.Name)
                    {
                        kullanici = kul;
                        break;
                    }
                }
            }
            comment.userID = kullanici.userID;
            comment.gameID = 9;
            if (comment != null)
            {
                _context.Add(comment);
                _context.SaveChanges();
            }

            return RedirectToAction("kader_karanligin_yukselisi", "Game");
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> kader_karanligin_yukselisi_al(Library library)
        {
            User kullanici = new User();
            if (User.Identity.IsAuthenticated)
            {
                foreach (var kul in _context.User)
                {
                    if (kul.userMail == User.Identity.Name)
                    {
                        kullanici = kul;
                        break;
                    }
                }
            }
            if (60 <= kullanici.userWallet)
            {
                kullanici.userWallet -= 60;
                library.userID = kullanici.userID;
                library.gameID = 9;
                if (library != null)
                {
                    _context.Add(library);
                    _context.Update(kullanici);
                    _context.SaveChanges();
                }
            }
            return RedirectToAction("kader_karanligin_yukselisi", "Game");
        }


        /// <summary>
        /// </summary>
        /// <returns></returns>
        public async Task<IActionResult> eski_tomarlar()
        {

            ViewModel viewModel = new ViewModel();

            viewModel.Users = _context.User.ToList();
            viewModel.Libraries = _context.Library.ToList();

            var Oyun = from a in _context.Game
                       where a.gameID == 11
                       select a;

            var yorum = from a in _context.Comment
                        where a.gameID == 11
                        select a;

            viewModel.Comments = yorum;
            viewModel.Games = Oyun;

            return View(viewModel);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> eski_tomarlar(Comment comment)
        {
            User kullanici = new User();
            if (User.Identity.IsAuthenticated)
            {
                foreach (var kul in _context.User)
                {
                    if (kul.userMail == User.Identity.Name)
                    {
                        kullanici = kul;
                        break;
                    }
                }
            }
            comment.userID = kullanici.userID;
            comment.gameID = 11;
            if (comment != null)
            {
                _context.Add(comment);
                _context.SaveChanges();
            }

            return RedirectToAction("eski_tomarlar", "Game");
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> eski_tomarlar_al(Library library)
        {
            User kullanici = new User();
            if (User.Identity.IsAuthenticated)
            {
                foreach (var kul in _context.User)
                {
                    if (kul.userMail == User.Identity.Name)
                    {
                        kullanici = kul;
                        break;
                    }
                }
            }
            if (20 <= kullanici.userWallet)
            {
                kullanici.userWallet -= 20;
                library.userID = kullanici.userID;
                library.gameID = 11;
                if (library != null)
                {
                    _context.Add(library);
                    _context.Update(kullanici);
                    _context.SaveChanges();
                }
            }
            return RedirectToAction("eski_tomarlar", "Game");
        }


        /// <summary>
        /// </summary>
        /// <returns></returns>
        public async Task<IActionResult> efsunger_vahsi_av()
        {

            ViewModel viewModel = new ViewModel();

            viewModel.Users = _context.User.ToList();
            viewModel.Libraries = _context.Library.ToList();

            var Oyun = from a in _context.Game
                       where a.gameID == 3
                       select a;

            var yorum = from a in _context.Comment
                        where a.gameID == 3
                        select a;

            viewModel.Comments = yorum;
            viewModel.Games = Oyun;

            return View(viewModel);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> efsunger_vahsi_av(Comment comment)
        {
            User kullanici = new User();
            if (User.Identity.IsAuthenticated)
            {
                foreach (var kul in _context.User)
                {
                    if (kul.userMail == User.Identity.Name)
                    {
                        kullanici = kul;
                        break;
                    }
                }
            }
            comment.userID = kullanici.userID;
            comment.gameID = 3;
            if (comment != null)
            {
                _context.Add(comment);
                _context.SaveChanges();
            }

            return RedirectToAction("efsunger_vahsi_av", "Game");
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> efsunger_vahsi_av_al(Library library)
        {
            User kullanici = new User();
            if (User.Identity.IsAuthenticated)
            {
                foreach (var kul in _context.User)
                {
                    if (kul.userMail == User.Identity.Name)
                    {
                        kullanici = kul;
                        break;
                    }
                }
            }
            if (120 <= kullanici.userWallet)
            {
                kullanici.userWallet -= 120;
                library.userID = kullanici.userID;
                library.gameID = 3;
                if (library != null)
                {
                    _context.Add(library);
                    _context.Update(kullanici);
                    _context.SaveChanges();
                }
            }
            return RedirectToAction("efsunger_vahsi_av", "Game");
        }

        // GET: Game/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var game = await _context.Game
                .FirstOrDefaultAsync(m => m.gameID == id);
            if (game == null)
            {
                return NotFound();
            }

            return View(game);
        }

        // GET: Game/Create
        public IActionResult Create()
        {
            return View();
        }

        // POST: Game/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to, for 
        // more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("gameID,gameName,gamePrice,gameGenre,gameRD,gameSold,gameDesc,gameURL,gameIMG")] Game game)
        {
            if (ModelState.IsValid)
            {
                _context.Add(game);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            return View(game);
        }

        // GET: Game/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var game = await _context.Game.FindAsync(id);
            if (game == null)
            {
                return NotFound();
            }
            return View(game);
        }

        // POST: Game/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to, for 
        // more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("gameID,gameName,gamePrice,gameGenre,gameRD,gameSold,gameDesc,gameURL,gameIMG")] Game game)
        {
            if (id != game.gameID)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(game);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!GameExists(game.gameID))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }
                return RedirectToAction(nameof(Index));
            }
            return View(game);
        }

        // GET: Game/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var game = await _context.Game
                .FirstOrDefaultAsync(m => m.gameID == id);
            if (game == null)
            {
                return NotFound();
            }

            return View(game);
        }

        // POST: Game/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var game = await _context.Game.FindAsync(id);
            _context.Game.Remove(game);
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool GameExists(int id)
        {
            return _context.Game.Any(e => e.gameID == id);
        }
    }
}
