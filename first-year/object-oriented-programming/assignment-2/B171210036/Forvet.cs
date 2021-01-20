using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B171210036
{
    class Forvet : Futbolcu
    {
        private double bitiricilik;
        private double ilkDokunus;
        private double kafaVurusYetenegi;
        private double ozelYetenek;
        private double sogukKanlilik;

        Random rastgeleSayi = new Random();
        public Forvet(string adSoyad, int formaNO) : base(adSoyad, formaNO)
        {
            this.adSoyad = adSoyad;
            this.formaNO = formaNO;
            this.dayaniklilik = rastgeleSayi.Next(70, 100);
            this.pasYetenegi = rastgeleSayi.Next(70, 100);
            this.sutYetenegi = rastgeleSayi.Next(70, 100);
            this.kararlilik = rastgeleSayi.Next(70, 100);
            this.dogalForm = rastgeleSayi.Next(70, 100);
            this.sans = rastgeleSayi.Next(70, 100);
            this.hiz = rastgeleSayi.Next(70, 100);
            this.yetenek = rastgeleSayi.Next(70, 100);
            this.bitiricilik = rastgeleSayi.Next(70, 100);
            this.ilkDokunus = rastgeleSayi.Next(70, 100);
            this.kafaVurusYetenegi = rastgeleSayi.Next(70, 100);
            this.ozelYetenek = rastgeleSayi.Next(70, 100);
            this.sogukKanlilik = rastgeleSayi.Next(70, 100);
        }

        public override void PasVer()
        {
            pasSkor = (this.pasYetenegi * 0.3)+ (this.yetenek * 0.2) + (this.ozelYetenek * 0.2) + (this.dayaniklilik * 0.1) + (this.dogalForm * 0.1) + (this.sans * 0.1);

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
            golSkor = (this.yetenek * 0.2) + (this.ozelYetenek * 0.2) + (this.sutYetenegi * 0.1) + (this.kafaVurusYetenegi * 0.1) + (this.ilkDokunus * 0.1) + (this.bitiricilik * 0.1) + (this.sogukKanlilik * 0.1) + (this.kararlilik * 0.1) + (this.dogalForm * 0.1) + (this.sans * 0.1);

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
