
namespace lab2 {

	class Julian : public lab2::Date {

		~Julian();
		
		std::string week_day_name() const;
		std::string month_name() const;
		int mod_julian_day() const;


	};

}