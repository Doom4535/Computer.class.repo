class TrafficLightLogic {
	int color;
public:
	//  Traffic lights always begin red
	TrafficLightLogic() : color(0) {}

	//  Cycle to the next color
	void change() {
		if (color == 2)
			color = 0;
		else
			color++;

	}

	//void change() {
	//	color = (color + 1) % 3;
	//}

	int get_color() {
		return color;
	}

};