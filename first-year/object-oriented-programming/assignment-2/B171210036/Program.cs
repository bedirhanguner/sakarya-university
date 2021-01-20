using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B171210036
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Futbolcu> Juventus = new List<Futbolcu>();

            Juventus.Add(new Defans("Joao Cancelo", 1));
            Juventus.Add(new Defans("Leonardo Bonucci", 2));
            Juventus.Add(new Defans("Giorgio Chiellini", 3));
            Juventus.Add(new Defans("Alex Sandro",4));
            Juventus.Add(new OrtaSaha("Blaise Matuidi", 5));
            Juventus.Add(new OrtaSaha("Miralem Pjanic", 6));
            Juventus.Add(new OrtaSaha("Douglas Costa", 7));
            Juventus.Add(new OrtaSaha("Paulo Dybala", 8));
            Juventus.Add(new OrtaSaha("Mario Mandzukic", 9));
            Juventus.Add(new Forvet("Cristiano Ronaldo", 10));
            Random rastgeleSayi = new Random();

            int FormaNo = 0;
            int PasVeren = 0;
            int GoluAatan = 0;

            for (int i = 1; i <= 3; i++)
            {
                PasVeren = FormaNo;
                FormaNo = rastgeleSayi.Next(1, 10);
                if (PasVeren == FormaNo)
                {
                    i--;
                }
                else
                {
                    Juventus[FormaNo].PasVer();
                    if (i == 3)
                    {
                        GoluAatan = FormaNo;
                        FormaNo = rastgeleSayi.Next(1, 10);
                        if (GoluAatan == FormaNo)
                        {
                            i--;
                        }
                        else
                        {
                            Juventus[FormaNo].GolVurusu();
                        }
                    }
                }
            }

            Console.ReadLine();

        }
    }
}
