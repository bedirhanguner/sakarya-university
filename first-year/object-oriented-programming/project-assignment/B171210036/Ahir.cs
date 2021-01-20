using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B171210036_1D_PROJE
{
    abstract class Ahir:IFonksiyonlar
    {
        protected int can;
        protected int sutLitresi;
        protected int sutFiyati;
        protected int canAzalmaMiktari;
        protected int uretimSikligi;

        public Ahir(int can, int sutLitresi, int sutFiyati, int canAzalmaMiktari, int uretimSikligi)
        {
            this.can = can;
            this.sutLitresi = sutLitresi;
            this.sutFiyati = sutFiyati;
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
        public int SutSat()
        {
            int kazanc = sutLitresi * sutFiyati;
            sutLitresi = 0;
            return kazanc;
        }

        public int SutUret()
        {
            sutLitresi++;
            return this.sutLitresi;
        }
    }
}
