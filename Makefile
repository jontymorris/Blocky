.PHONY: clean All

All:
	@echo "----------Building project:[ Blocky - Debug ]----------"
	@"$(MAKE)" -f  "Blocky.mk"
clean:
	@echo "----------Cleaning project:[ Blocky - Debug ]----------"
	@"$(MAKE)" -f  "Blocky.mk" clean
