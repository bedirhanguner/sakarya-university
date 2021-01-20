using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B171210036
{
    abstract class Futbolcu
    {
        protected string adSoyad;
        protected int formaNO;
        protected double hiz;
        protected double dayaniklilik;
        protected double pasYetenegi;
        protected double sutYetenegi;
        protected double yetenek;
        protected double kararlilik;
        protected double dogalForm;
        protected double sans;

        protected double golSkor;
        protected double pasSkor;

        Random rastgeleSayi = new Random();

        public Futbolcu(string adSoyad, int formaNO)
        {
            this.adSoyad = adSoyad;
            this.formaNO = formaNO;

            this.pasYetenegi = rastgeleSayi.Next(50, 100);
            this.dayaniklilik = rastgeleSayi.Next(50, 100);
            this.dogalForm = rastgeleSayi.Next(50, 100);
            this.sans = rastgeleSayi.Next(50, 100);
            this.sutYetenegi = rastgeleSayi.Next(50, 100);
            this.kararlilik = rastgeleSayi.Next(50, 100);
            this.hiz = rastgeleSayi.Next(50, 100);
            this.yetenek = rastgeleSayi.Next(50, 100);
        }
        public virtual void PasVer()
        {
            pasSkor = (this.pasYetenegi * 0.3) + (this.yetenek * 0.3) + (this.dayaniklilik * 0.1) + (this.dogalForm * 0.1) + (this.sans * 0.2);

           if (pasSkor >= 60)
            {
                Console.WriteLine("Pas Başarılı! "+formaNO +" Forma Numaralı "+ adSoyad+ " dan pas!\n");
                
            }

             else
            {
                Console.WriteLine("Pas Başarısız...");
                Console.ReadLine();

                Environment.Exit(0);            
            }
            
        }

        public virtual void GolVurusu()
        { 
            golSkor = (this.yetenek * 0.3) + (this.sutYetenegi * 0.2) + (this.kararlilik * 0.1) + (this.dogalForm * 0.1) + (this.hiz * 0.1) + (this.sans * 0.2);

            if (golSkor >= 70)
            {

                Console.WriteLine("GOOOOOLLL!!! "+formaNO+" Forma Numaralı "+ adSoyad+" Golü Buluyor!");
            }
            else
            {
                Console.WriteLine("Gol fırsatı kaçtı...");
            }
        }
    }
}
