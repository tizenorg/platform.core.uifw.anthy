%define __libtoolize :

#
Summary: A Japanese character input system library.(with dictionary)
Name: anthy
Version: 9100h
Release: 1
URL: http://www.sourceforge.jp/projects/anthy/
Source0: %{name}-%{version}.tar.gz
Source1001: 	anthy.manifest
#
# URL: http://cannadic.oucrc.org
# Source1: cannadic-0.93.tar.gz
License: GPL
Group: System Environment/Libraries
BuildRoot: %{_tmppath}/%{name}-root

%description

%prep
%setup -q
cp %{SOURCE1001} .
#tar zxf %{_sourcedir}/cannadic-0.93.tar.gz
#ln -s ../cannadic-0.93/gcanna.t mkanthydic
#ln -s ../cannadic-0.93/gcannaf.t mkanthydic

%build
%configure

make

%install
rm -rf ${RPM_BUILD_ROOT}
mkdir -p %{buildroot}%{_datadir}/license
cp COPYING %{buildroot}%{_datadir}/license/%{name}
%makeinstall

%clean
rm -rf ${RPM_BUILD_ROOT}

%post
/sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%manifest %{name}.manifest
%defattr(-,root,root)
%{_datadir}/license/%{name}
%{_bindir}/*
%{_sysconfdir}/*
%{_datadir}/anthy
#%{_datadir}/emacs/site-lisp/*
%{_libdir}/pkgconfig/*
%{_libdir}/libanthy*
%{_includedir}/*
#%doc README doc

%changelog
* Thu Jan  3 2002 Yusuke Tabata <yusuke@kmc.gr.jp>
- changed my mail address and URL of web page

* Thu Nov 11 2001 Takayoshi Nobuoka <taka@trans-nt.com>
- add %{_sysconfdir}/* at %files

* Wed Sep  9 2001 Takayoshi Nobuoka <taka@trans-nt.com>
- use _bindir and so on.

* Sun Aug 19 2001 Tabatee <yusuke@kmc.kyoto-u.ac.jp>
- Initial build.
