using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B171210036
{
    class Defans : Futbolcu
    {
        private double pozisyonAlma;
        private double kafaVurusYetenegi;
        private double sicramaGucu;

        Random rastgeleSayi = new Random();

        public Defans(string adSoyad, int formaNO) : base(adSoyad, formaNO)
        {
            this.adSoyad = adSoyad;
            this.formaNO = formaNO;

            this.dayaniklilik = rastgeleSayi.Next(50, 90);
            this.pasYetenegi = rastgeleSayi.Next(50, 90);
            this.sutYetenegi = rastgeleSayi.Next(50, 90);
            this.kararlilik = rastgeleSayi.Next(50, 90);
            this.dogalForm = rastgeleSayi.Next(50, 90);
            this.sans = rastgeleSayi.Next(50, 90);
            this.hiz = rastgeleSayi.Next(50, 90);
            this.yetenek = rastgeleSayi.Next(50, 90);
            this.pozisyonAlma = rastgeleSayi.Next(50, 90);
            this.kafaVurusYetenegi = rastgeleSayi.Next(50, 90);
            this.sicramaGucu = rastgeleSayi.Next(50, 90);
        }
        public override void PasVer()
        {
            pasSkor = (this.pasYetenegi * 0.3) + (this.yetenek * 0.3) + (this.dayaniklilik * 0.1) + (this.dogalForm * 0.1) + (this.pozisyonAlma * 0.1) + (this.sans * 0.2);

            if (pasSkor >= 60)
            {
                Console.WriteLine("Pas Başarılı! " + formaNO + " Forma Numaralı " + adSoyad + " dan pas!\n");
            }
            else
            {
                Console.WriteLine("Pas Başarısız...");
                Console.ReadLine();
                Environment.Exit(0);
            }
        }

        public override void GolVurusu()
        {
            golSkor = (this.yetenek * 0.3) + (this.sutYetenegi * 0.2) + (this.kararlilik * 0.1) + (this.dogalForm * 0.1) + (this.kafaVurusYetenegi * 0.1) + (this.sicramaGucu * 0.1) + (this.sans * 0.1);

            if (golSkor >= 70)
            {
                Console.WriteLine("GOOOOOLLL!!! " + formaNO + " Forma Numaralı " + adSoyad + " Golü Buluyor!");
            }
            else
            {
                Console.WriteLine("Gol fırsatı kaçtı...");
            }
        }
    }
}
