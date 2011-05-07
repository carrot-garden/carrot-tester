package case_01;

public enum OS {
	
	NONE("???"), //
	
	WINDOWS("Windows"),//
	
	LINUX("Linux"), //
	
	;
	
	private final String code;
	
	OS(String code){
		this.code = code;
	}

	public static OS fromCode(String code){
		if(code == null){
			return NONE;
		}
		for(OS os : values()){
			if(code.contains(os.code)){
				return os;
			}
		}
		return NONE;
	}
	
	public static OS detect(){
		String code = System.getProperty("os.name");
		return fromCode(code);
	}
	
}
