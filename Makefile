all:
	$(MAKE) -C $(PWD)/single_linklist/
	$(MAKE) -C $(PWD)/double_linklist/
	$(MAKE) -C $(PWD)/double_linklist_opt/

clean:
	$(MAKE) -C $(PWD)/single_linklist/ clean
	$(MAKE) -C $(PWD)/double_linklist/ clean
	$(MAKE) -C $(PWD)/double_linklist_opt/ clean
