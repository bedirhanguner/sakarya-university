using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B171210036
{
    class OrtaSaha : Futbolcu
    {
        private double uzunTopYetenegi;
        private double ilkDokunus;
        private double uretkenlik;
        private double topSurme;
        private double ozelYetenek;

        Random rastgeleSayi = new Random();

        public OrtaSaha(string adSoyad, int formaNO) : base(adSoyad, formaNO)
        {
            this.adSoyad = adSoyad;
            this.formaNO = formaNO;

            this.dayaniklilik = rastgeleSayi.Next(60, 100);
            this.pasYetenegi = rastgeleSayi.Next(60, 100);
            this.sutYetenegi = rastgeleSayi.Next(60, 100);
            this.kararlilik = rastgeleSayi.Next(60, 100);
            this.dogalForm = rastgeleSayi.Next(60, 100);
            this.sans = rastgeleSayi.Next(60, 100);
            this.hiz = rastgeleSayi.Next(60, 100);
            this.yetenek = rastgeleSayi.Next(60, 100);
            this.uzunTopYetenegi = rastgeleSayi.Next(60, 100);
            this.ilkDokunus = rastgeleSayi.Next(60, 100);
            this.uretkenlik = rastgeleSayi.Next(60, 100);
            this.topSurme = rastgeleSayi.Next(60, 100);
            this.ozelYetenek = rastgeleSayi.Next(60, 100);
        }

        public override void PasVer()
        {
            pasSkor = (this.pasSkor * 0.3) + (this.yetenek * 0.2) + (this.ozelYetenek * 0.2) + (this.dayaniklilik * 0.1) + (this.dogalForm * 0.1) + (this.uzunTopYetenegi * 0.1) + (this.topSurme * 0.1) + (this.sans * 0.1);

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
            golSkor = (this.yetenek * 0.3) + (this.ozelYetenek * 0.2) + (this.sutYetenegi * 0.2) + (this.ilkDokunus * 0.1) + (this.kararlilik * 0.1) + (this.dogalForm * 0.1) + (this.sans * 0.1);

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


