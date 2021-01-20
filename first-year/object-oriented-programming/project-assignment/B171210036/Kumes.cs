using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B171210036_1D_PROJE
{
     abstract class Kumes:IFonksiyonlar
    {
        protected int can;
        protected int yumurtaSayisi;
        protected int yumurtaFiyati;
        protected int canAzalmaMiktari;
        protected int uretimSikligi;
        public Kumes(int can, int yumurtaSayisi, int yumurtaFiyati, int canAzalmaMiktari, int uretimSikligi)
        {
            this.can = can;
            this.yumurtaSayisi = yumurtaSayisi;
            this.yumurtaFiyati = yumurtaFiyati;
            this.canAzalmaMiktari = canAzalmaMiktari;
            this.uretimSikligi = uretimSikligi;
        }

        public int CanAzalmaMiktari
        {
            get
            {
                return canAzalmaMiktari;
            }

            set
            {
                if (canAzalmaMiktari < 0)
                {
                    canAzalmaMiktari = 0;
                }

                else
                value = canAzalmaMiktari;
            }
        }

        public int UretimSikligi
        {
            get
            {
                return uretimSikligi;
            }

            set
            {
                if (uretimSikligi < 0)
                {
                    uretimSikligi = 0;
                }

                else
                value = uretimSikligi;
            }
        }
        public int CanAzalt()
        {
            can -= canAzalmaMiktari;
            return this.can;
        }

        public int CanTazele()
        {
            can = 100;
            return can;
        }

         public int YumurtaSat()
        {
            int kazanc = yumurtaSayisi * yumurtaFiyati;
            yumurtaSayisi = 0;
            return kazanc;
        }

        public int YumurtaUret()
        {
            yumurtaSayisi++;
            return this.yumurtaSayisi;
        }
    }
}
