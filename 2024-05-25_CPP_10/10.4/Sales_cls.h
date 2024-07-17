#ifndef __SALES_H__
#define __SALES_H__
namespace SALES {
    const int QUARTERS = 4;
    class Sales {
      private:
        double sales[QUARTERS];
        double average;
        double max;
        double min;
        void setSales(const double ar[], int n);

      public:
        Sales(const double ar[], int n);
        Sales();
        void showSales() const;
    };
}  // namespace SALES
#endif  // !__SALES_H__
