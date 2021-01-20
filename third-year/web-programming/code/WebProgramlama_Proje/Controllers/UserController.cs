using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Claims;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Authentication;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using WebProgramlama_Proje.Data;
using WebProgramlama_Proje.Models;

namespace WebProgramlama_Proje.Controllers
{
    public class UserController : Controller
    {
        //private MuslukDbContext _context;
        //public UserController(MuslukDbContext context)
        //{
        //    _context = context;
        //}

        MuslukDbContext mdb;

        public UserController(MuslukDbContext context)
        {
            mdb = context;
        }


        [HttpGet]
        public IActionResult Login()
        {
            return View();
        }

        public async Task<IActionResult> Login(User u)
        {
            var bilgiler = mdb.User.FirstOrDefault(x => x.userMail == u.userMail && x.userPass == u.userPass);
            
            if (bilgiler != null)
            {
                var bulunan = mdb.User.Where(i => i.userMail == u.userMail).FirstOrDefault();
                mdb.SaveChanges();
                var claims = new List<Claim>
                {
                    new Claim(ClaimTypes.Name,u.userMail)
                };
                var useridentity = new ClaimsIdentity(claims, "Login");
                ClaimsPrincipal principal = new ClaimsPrincipal(useridentity);
                await HttpContext.SignInAsync(principal);
                
                return RedirectToAction("Index", "Store");
            }

            return View();
        }

        [HttpPost]
        public async Task<IActionResult> Logout()
        {
            await HttpContext.SignOutAsync();
            return RedirectToAction("Index", "Home");
        }


        User gc = new User();

        // GET: User
        [Authorize]
        public async Task<IActionResult> Index()
        {

            ViewModel viewModel = new ViewModel();

            viewModel.Users = mdb.User.ToList();
            viewModel.Comments = mdb.Comment.ToList();
            viewModel.Games = mdb.Game.ToList();
            viewModel.Libraries = mdb.Library.ToList();

            return View(viewModel);
        }

        [Authorize]
        public async Task<IActionResult> AdminPanel()
        {

            ViewModel viewModel = new ViewModel();

            viewModel.Users = mdb.User.ToList();
            viewModel.Comments = mdb.Comment.ToList();
            viewModel.Games = mdb.Game.ToList();
            viewModel.Libraries = mdb.Library.ToList();

            return View(viewModel);
        }

        // GET: User/Details/5
        public async Task<IActionResult> Profile()
        {
            ViewModel viewModel = new ViewModel();

            viewModel.Users = mdb.User.ToList();
            viewModel.Comments = mdb.Comment.ToList();
            viewModel.Games = mdb.Game.ToList();
            viewModel.Libraries = mdb.Library.ToList();

            return View(viewModel);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> bakiyeEkleOn(int bakiye)
        {
            User kullanici = new User();
            if (User.Identity.IsAuthenticated)
            {
                foreach (var kul in mdb.User)
                {
                    if (kul.userMail == User.Identity.Name)
                    {
                        kullanici = kul;
                        break;
                    }
                }
            }
            kullanici.userWallet += 10;
            mdb.Update(kullanici);
            mdb.SaveChanges();

            return RedirectToAction("Profile", "User");
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> bakiyeEkleYirmi(int bakiye)
        {
            User kullanici = new User();
            if (User.Identity.IsAuthenticated)
            {
                foreach (var kul in mdb.User)
                {
                    if (kul.userMail == User.Identity.Name)
                    {
                        kullanici = kul;
                        break;
                    }
                }
            }
            kullanici.userWallet += 20;
            mdb.Update(kullanici);
            mdb.SaveChanges();

            return RedirectToAction("Profile", "User");
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> bakiyeEkleElli(int bakiye)
        {
            User kullanici = new User();
            if (User.Identity.IsAuthenticated)
            {
                foreach (var kul in mdb.User)
                {
                    if (kul.userMail == User.Identity.Name)
                    {
                        kullanici = kul;
                        break;
                    }
                }
            }
            kullanici.userWallet += 50;
            mdb.Update(kullanici);
            mdb.SaveChanges();

            return RedirectToAction("Profile", "User");
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> bakiyeEkleYuz(int bakiye)
        {
            User kullanici = new User();
            if (User.Identity.IsAuthenticated)
            {
                foreach (var kul in mdb.User)
                {
                    if (kul.userMail == User.Identity.Name)
                    {
                        kullanici = kul;
                        break;
                    }
                }
            }
            kullanici.userWallet += 100;
            mdb.Update(kullanici);
            mdb.SaveChanges();

            return RedirectToAction("Profile", "User");
        }


        // GET: User/Create
        public IActionResult Create()
        {
            return View();
        }

        // POST: User/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to, for 
        // more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("userID,userName,userPass,userMail,userWallet")] User user)
        {
            if (ModelState.IsValid)
            {
                mdb.Add(user);
                await mdb.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            return View(user);
        }

        // GET: User/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var user = await mdb.User.FindAsync(id);
            if (user == null)
            {
                return NotFound();
            }
            return View(user);
        }

        // POST: User/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to, for 
        // more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("userID,userName,userPass,userMail,userWallet")] User user)
        {
            if (id != user.userID)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    mdb.Update(user);
                    await mdb.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!UserExists(user.userID))
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
            return View(user);
        }

        // GET: User/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var user = await mdb.User
                .FirstOrDefaultAsync(m => m.userID == id);
            if (user == null)
            {
                return NotFound();
            }

            return View(user);
        }

        // POST: User/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var user = await mdb.User.FindAsync(id);
            mdb.User.Remove(user);
            await mdb.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool UserExists(int id)
        {
            return mdb.User.Any(e => e.userID == id);
        }
    }
}
